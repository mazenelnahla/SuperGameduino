/*
  Created by Fabrizio Di Vittorio (fdivitto2013@gmail.com) - <http://www.fabgl.com>
  Copyright (c) 2019-2022 Fabrizio Di Vittorio.
  All rights reserved.


* Please contact fdivitto2013@gmail.com if you need a commercial license.


* This library and related software is available under GPL v3.

  FabGL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  FabGL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with FabGL.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "fabgl.h"


fabgl::VGADirectController DisplayController;


volatile double      objX                 = 300;
volatile double      objY                 = 200;
static double        objDir               = 0.3;
static double        objVel               =  10;
static constexpr int objSize              =  25;
static uint32_t      bgParkMillerState    = 1;
static constexpr int borderSize           = 20;
constexpr int        scanlinesPerCallback = 2;  // screen height should be divisible by this value

static TaskHandle_t  mainTaskHandle;


// just to avoid floating point calculations inside MyDirectDrawVGAController::drawScanline()
volatile int objIntX;
volatile int objIntY;


inline int fastRandom()
{
  bgParkMillerState = (uint64_t)bgParkMillerState * 48271 % 0x7fffffff;
  return bgParkMillerState % 4;
}


void IRAM_ATTR drawScanline(void * arg, uint8_t * dest, int scanLine)
{
  auto fgcolor = DisplayController.createRawPixel(RGB222(3, 0, 0)); // red
  auto bgcolor = DisplayController.createRawPixel(RGB222(0, 0, 2)); // blue

  auto width  = DisplayController.getScreenWidth();
  auto height = DisplayController.getScreenHeight();

  // draws "scanlinesPerCallback" scanlines every time drawScanline() is called
  for (int i = 0; i < scanlinesPerCallback; ++i) {

    // fill upper and lower border with random background color
    if (scanLine < borderSize || scanLine > height - borderSize)
      bgcolor = DisplayController.createRawPixel(RGB222(fastRandom(), fastRandom(), fastRandom()));

    // fill line with background color
    memset(dest, bgcolor, width);

    // fill object with foreground color
    if (scanLine >= objIntY - objSize / 2 && scanLine <= objIntY + objSize / 2) {
      for (int col = objIntX - objSize / 2; col < objIntX + objSize / 2; ++col) {
        if (col >= 0 && col < width) {
          VGA_PIXELINROW(dest, col) = fgcolor;
        }
      }
    }

    // go to next scanline
    ++scanLine;
    dest += width;

  }

  if (scanLine == height) {
    // signal end of screen
    vTaskNotifyGiveFromISR(mainTaskHandle, NULL);
  }
}


void setup()
{
  //Serial.begin(115200); delay(500); Serial.write("\n\n\n"); // DEBUG ONLY

  mainTaskHandle = xTaskGetCurrentTaskHandle();

  DisplayController.begin();
  DisplayController.setScanlinesPerCallBack(scanlinesPerCallback);
  DisplayController.setDrawScanlineCallback(drawScanline);
  DisplayController.setResolution(VGA_640x480_60Hz);
}


void loop()
{
  // test collision with borders and bounce changing direction
  if (objX < objSize / 2 || objX > DisplayController.getScreenWidth() - objSize / 2)
    objDir = PI - objDir;
  else if (objY < borderSize + objSize / 2 || objY > DisplayController.getScreenHeight() - borderSize - objSize / 2)
    objDir = 2 * PI - objDir;

  // calculate new coordinates
  objX += objVel * cos(objDir);
  objY += objVel * sin(objDir);

  // convert object coordinate to integer
  objIntX = objX;
  objIntY = objY;

  // wait for vertical sync
  ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
}
