function atualizarRelogio() {
    const agora = new Date();
    const relogioElemento = document.getElementById("relogio");

    // Formata a data e hora (personalize como quiser)
    const dataFormatada = agora.toLocaleDateString('pt-BR');
    const horaFormatada = agora.toLocaleTimeString('pt-BR');

    // Exibe no HTML
    relogioElemento.innerHTML = `
        <strong>Data:</strong> ${dataFormatada} <br>
        <strong>Hora:</strong> ${horaFormatada}
    `;
}

// Atualiza a cada 1 segundo
setInterval(atualizarRelogio, 1000);

// Chama a função imediatamente para evitar delay
atualizarRelogio();