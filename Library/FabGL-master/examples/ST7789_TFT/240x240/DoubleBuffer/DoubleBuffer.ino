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


/*
 * TFT Display signals:
 *   SCK  => GPIO 18
 *   MOSI => GPIO 23
 *   D/C  => GPIO 22
 *   RESX => GPIO 21
 */



#include "fabgl.h"


#define TFT_SCK    18
#define TFT_MOSI   23
#define TFT_DC     22
#define TFT_RESET  21
#define TFT_SPIBUS VSPI_HOST



fabgl::ST7789Controller DisplayController;
fabgl::Canvas           canvas(&DisplayController);



#define DOUBLEBUFFERING 1


struct Test {
  virtual ~Test() { };
  virtual void update() = 0;
  virtual bool nextState() = 0;
  virtual int testState() = 0;
  virtual char const * name() = 0;
};


#include "ballstest.h"
#include "polygonstest.h"
#include "spritestest.h"



void setup()
{
  DisplayController.begin(TFT_SCK, TFT_MOSI, TFT_DC, TFT_RESET, -1, TFT_SPIBUS);
  DisplayController.setResolution(TFT_240x240, -1, -1, DOUBLEBUFFERING);

  // get a font for about 40x14 text screen
  canvas.selectFont(&fabgl::FONT_9x18);

  canvas.setGlyphOptions(GlyphOptions().FillBackground(true));
}


void loop()
{
  static int64_t stime  = esp_timer_get_time();
  static int FPS        = 0;
  static int FPSCounter = 0;
  static int testIndex  = 0;
  static Test * test    = new BallsTest;

  if (test->nextState() == false) {
    delete test;
    ++testIndex;
    switch (testIndex) {
      case 1:
        test = new PolygonsTest;
        break;
      case 2:
        test = new SpritesTest;
        break;
      default:
        testIndex = 0;
        test = new BallsTest;
        break;
    }
  }

  if (esp_timer_get_time() - stime > 1000000) {
    // calculate FPS
    FPS = FPSCounter;
    stime = esp_timer_get_time();
    FPSCounter = 0;
  }
  ++FPSCounter;

  test->update();

  // display test state and FPS
  canvas.setPenColor(Color::Blue);
  canvas.setBrushColor(Color::BrightYellow);
  canvas.drawTextFmt(0, 0, " %d %s at %d FPS ", test->testState(), test->name(), FPS);

  if (DOUBLEBUFFERING)
    canvas.swapBuffers();

}
