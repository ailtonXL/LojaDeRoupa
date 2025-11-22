from flask import Flask, render_template_string, jsonify
from datetime import datetime

app = Flask(__name__)

# Configuração da data inicial
INICIO = datetime.strptime("2024-10-20 16:29:00", "%Y-%m-%d %H:%M:%S")

# Template HTML com CSS responsivo
HTML_TEMPLATE = """
<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
    <title>Relógio do Amor</title>
    <style>
        :root {
            --cor-primaria: #ff6b81;
            --cor-secundaria: #ff4757;
            --cor-fundo: #fff9f9;
        }

        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

        body {
            font-family: 'Arial', sans-serif;
            background: var(--cor-fundo);
            color: #333;
            line-height: 1.6;
            min-height: 100vh;
            display: flex;
            justify-content: center;
            align-items: center;
            padding: 20px;
        }

        .container {
            width: 100%;
            max-width: 500px;
            background: white;
            border-radius: 15px;
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.1);
            padding: 25px;
            text-align: center;
            margin: 20px 0;
        }

        h1 {
            color: var(--cor-primaria);
            margin-bottom: 15px;
            font-size: clamp(1.5rem, 5vw, 2rem);
        }

        .couple {
            font-size: clamp(1.2rem, 4vw, 1.8rem);
            color: var(--cor-secundaria);
            font-weight: bold;
            margin: 15px 0;
        }

        .start-date {
            font-size: clamp(0.9rem, 3vw, 1.1rem);
            margin-bottom: 20px;
            color: #666;
        }

        .timer-container {
            background: #fff;
            border-radius: 10px;
            padding: 15px;
            margin: 20px 0;
            box-shadow: 0 3px 10px rgba(0, 0, 0, 0.05);
        }

        #timer {
            font-size: clamp(1rem, 4vw, 1.3rem);
            line-height: 1.8;
        }

        .heart {
            color: var(--cor-primaria);
            font-size: 1.5rem;
            display: inline-block;
            animation: pulse 1.5s infinite;
            margin: 0 5px;
        }

        @keyframes pulse {
            0% { transform: scale(1); }
            50% { transform: scale(1.2); }
            100% { transform: scale(1); }
        }

        /* Ajustes para telas muito pequenas */
        @media (max-width: 400px) {
            .container {
                padding: 15px;
                border-radius: 10px;
            }

            #timer {
                font-size: 0.9rem;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Relógio do Amor <span class="heart">❤️</span></h1>
        <p class="couple">Hemilli & Ailton</p>
        <p class="start-date">Juntos desde: 20/10/2024 16:29</p>

        <div class="timer-container">
            <p>Vocês estão juntos há:</p>
            <p id="timer">Carregando...</p>
        </div>
    </div>

    <script>
        function updateTime() {
            fetch('/time')
                .then(response => {
                    if (!response.ok) throw new Error('Erro na rede');
                    return response.json();
                })
                .then(data => {
                    document.getElementById('timer').innerText = data.time;
                })
                .catch(error => {
                    console.error('Erro:', error);
                    document.getElementById('timer').innerText = "Atualizando...";
                    setTimeout(updateTime, 2000);
                });
        }

        // Atualiza imediatamente e a cada segundo
        updateTime();
        setInterval(updateTime, 1000);

        // Melhorias para mobile
        document.addEventListener('touchstart', function(){}, {passive: true});
    </script>
</body>
</html>
"""

@app.route('/')
def index():
    return render_template_string(HTML_TEMPLATE)

@app.route('/time')
def time_elapsed():
    agora = datetime.now()
    diferenca = agora - INICIO

    dias = diferenca.days
    segundos_totais = diferenca.seconds
    horas = segundos_totais // 3600
    minutos = (segundos_totais % 3600) // 60
    segundos = segundos_totais % 60

    tempo_formatado = f"{dias} dias, {horas} horas, {minutos} minutos e {segundos} segundos"
    return jsonify({"time": tempo_formatado})

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080)