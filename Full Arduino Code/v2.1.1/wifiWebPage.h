const char wifiWebPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <title>E-Paper</title>
    <meta content="width=device-width, initial-scale=1 max, maximum-scale=1, user-scalable=no" charset="utf-8" />
    <link rel="icon"
        href="data:image/png;base64,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" />

    <script type="text/javascript">
        function sendWifiSettings() {
            var formData = new FormData(document.getElementById("wifiForm"));
            var xhttp = new XMLHttpRequest();
            xhttp.open("POST", "/wifi", true);
            xhttp.send(formData);
        };
    </script>

    <style>
        .container {
            background-color: #ffffff60;
            width: 90%;
            height: auto;
            border: 5px #303030 solid;
            border-radius: 40px;
            margin-top: 5%;
            margin-left: auto;
            margin-right: auto;
            text-align: center;
        }

        .titleContainer {
            display: inline-block;
            font-size: 200%;
            font-family: Gill Sans;
            margin: auto;
        }

        .subtitle {
            color: rgb(0, 0, 0);
            font-size: 150%;
            font-family: Gill Sans;
        }

        .inputText {
            height: auto;
            width: 90%;
            font-size: 150%;
            text-align: center;
            border: 1px #000000 solid;
            border-radius: 8px;
            background-color: #ffffff75;
        }

        .button {
            height: auto;
            width: 40%;
            background-color: #303030;
            color: #fff;
            border-radius: 15px;
            font-family: Gill Sans;
            font-size: 150%;
            margin: auto;
            border: 1px #ffffff solid;
        }

        body {
            padding-top: 13%;
            max-width: 1000px;
            margin: auto;
        }

        .bg {
            animation: slide 3s ease-in-out infinite alternate;
            background-image: linear-gradient(-60deg, rgb(56, 56, 56) 50%, rgb(255, 255, 255) 50%);
            bottom: 0;
            left: -50%;
            opacity: .5;
            position: fixed;
            right: -50%;
            top: 0;
            z-index: -1;
        }

        .bg2 {
            animation-direction: alternate-reverse;
            animation-duration: 4s;
        }

        .bg3 {
            animation-duration: 5s;
        }

        .content {
            background-color: rgba(255, 255, 255, .8);
            border-radius: .25em;
            box-shadow: 0 0 .25em rgba(0, 0, 0, .25);
            box-sizing: border-box;
            left: 50%;
            padding: 10vmin;
            position: fixed;
            text-align: center;
            top: 50%;
            transform: translate(-50%, -50%);
        }



        @keyframes slide {
            0% {
                transform: translateX(-25%);
            }

            100% {
                transform: translateX(25%);
            }
        }

        .header {
            z-index: 1;
            position: fixed;
            left: 0;
            top: 0;
            color: white;
            background-color: #303030;
            width: 100%;
            height: auto;
            padding: 10px;
            font-size: 300%;
            text-align: center;
            font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
            padding-top: 1%;
        }
    </style>
</head>
<div class="bg"></div>
<div class="bg bg2"></div>
<div class="bg bg3"></div>

<body class="body" id="bodyWifi">
    <header class="header">Homey e-paper</header>
    <form class="container" id="wifiForm" method="post">
        <p class="titleContainer">WiFi Settings</p>
        <br>
        <br>
        <br>
        <label for="SSID" class="subtitle">SSID</label>
        <br>
        <input type="text" class="inputText" name="SSID" id="SSID" placeholder="Your SSID">
        <br>
        <br>
        <br>
        <label for="PASSWORD" class="subtitle">PASSWORD</label>
        <br>
        <input type="text" class="inputText" name="PASSWORD" id="PASSWORD" placeholder="Your password">
        <br>
        <br>
        <br>
        <br>
        <button class="button" id="wifiButton" onclick=sendWifiSettings()>Send</button>
        <br>
        <br>
        </div>
</body>
)=====";
