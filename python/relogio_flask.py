from flask import Flask, render_template_string
from datetime import datetime
import threading
import time

app = Flask(__name__)

#Define a data e hora
data_inicio = "2024-10-20"
hora_inicio = "16:29:00"
inicio_str = f"{data_inicio} {hora_inicio}"
inicio = datetime.strptime(inicio_str, "%Y-%m-%d %H:%M:%S")

#HTML
html_template = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Relógio do Amor</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #f7f7f7;
        }
        .container {
            text-align: center;
            background: #ffe4e1;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        }
        h1 {
            color: #ff69b4;
        }
        p {
            font-size: 1.5rem;
            color: #333;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Relógio do Amor ❤️</h1>
        <p>Hemilli & Ailton</p>
        <p>Vocês estão juntos há:</p>
        <p id="timer"></p>
    </div>

    <script>
        function updateTime() {
            fetch('/time').then(response => response.json()).then(data => {
                document.getElementById('timer').innerText = data.time;
            });
        }
        setInterval(updateTime, 1000);
        updateTime();
    </script>
</body>
</html>
"""

@app.route('/')
def index():
    return render_template_string(html_template)

@app.route('/time')
def time_elapsed():
    agora = datetime.now()
    diferenca = agora - inicio

    dias = diferenca.days
    segundos_totais = diferenca.seconds
    horas = segundos_totais // 3600
    minutos = (segundos_totais % 3600) // 60
    segundos = segundos_totais % 60

    tempo_formatado = f"{dias} dias, {horas} horas, {minutos} minutos e {segundos} segundos"
    return {"time": tempo_formatado}

if __name__ == "__main__":
    app.run(debug=True, host='0.0.0.0', port=5000)
