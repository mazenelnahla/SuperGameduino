R"(
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>SuperGameduino Terminal</title>
	<script>
		function load() {
			document.querySelector('#in').focus();
		}

		function send() {
			var e = document.querySelector('#in');
			var xhr = new XMLHttpRequest();
			xhr.open('POST', '/text');
			xhr.send(e.value);
			document.querySelector("#log").innerHTML = e.value + "\n" + document.querySelector("#log").innerHTML;
			e.value = '';
		}
	</script>
	<style>
		h1
			{
				color: white;
				background: #000000;
				padding: 10px;
				margin-bottom: 5px;
				text-align: center;
                margin: 0;
			}
			body
			{
                display: flex;
                flex-direction: column;
                min-height: 100vh;
				font-family: monospace;
				padding: 0;
                margin: 0;
			}
			input, textarea, button
			{
				border-style: solid;
                border-width: 2px;
				border-radius: 9px;
                border-color: green;
			}
			#send 
			{
                background-color: #4CAF50; /* Green */
                border: none;
                color: white;
                padding: 5px 15px;
                text-align: center;
                text-decoration: none;
                display: block;
                font-size: 16px;
                margin-bottom: 5px;
                float: right;
                border-radius: 5px;
			}
			#in{
                display: block;
                float: left;
                padding: 5px 15px;
				margin-bottom: 5px;
                width: 100%;
			}
			#log
			{
                display: block;
				resize: none;
				height: 300px;
				width: 100%;
			}

			table
			{
                width: 80%;
                margin-left: auto;
                margin-right: auto;
			}
            td.min{
                width: 0;
            }
            .fo{
                margin-top: auto;
                background: #000000;
                color: white;
                padding: 0px;
             }
            .te{
                padding-left: 10px;
				text-align: left;
                text-transform: uppercase;
                float: left;
             }
             .fl{
                float:right;
             }
             a:link, a:visited {
                color: white;
                text-transform: uppercase;
                padding: 14px 10px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
            }

            a:hover, a:active {
                background-color: green;
            }
		</style>
</head>

<body onload='load()'>
	<h1>SuperGameduino Terminal</h1>
	<table>
		<tr>
			<p style="margin-top: auto; text-align: center;font-size: 15px;font-weight: bold;">Enter The Text You Want</p>
			<td><input id='in' type='text' tabindex=1 onchange='send()' autocomplete='off'></td>
			<td class='min'><button id='send' onclick='send()'>Send</button></td>
		</tr>
		<tr>
			<td colspan=2>
				<textarea id='log' readonly></textarea>
			</td>
		</tr>
	</table>
    <footer class="fo">
        <p class="te">this page was made by mazen elnahla</p>
        <div class="fl">
            <a class="flinks" href="">games</a>
            <a class="flinks" href="">room control</a>
            <a class="flinks" style="background-color: green;" href="">Terminal</a>
        </div>
    </footer>
</body>
</html>


)"