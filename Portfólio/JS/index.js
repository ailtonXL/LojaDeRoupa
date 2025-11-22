// side-bar e funcionalidades da página
document.addEventListener('DOMContentLoaded', function() {
    // Código para a barra lateral
    const menuToggle = document.querySelector('.menu-toggle');
    const sidebar = document.querySelector('.sidebar');

    menuToggle.addEventListener('click', function() {
        sidebar.classList.toggle('show-sidebar');
    });

    // Código para copiar o e-mail
    const emailIcon = document.getElementById('email-icon');
    const copyMessage = document.getElementById('copy-message');

    if (emailIcon) {
        emailIcon.addEventListener('click', function(e) {
            e.preventDefault();
            
            const email = this.getAttribute('data-email');
            
            navigator.clipboard.writeText(email).then(function() {
                copyMessage.classList.add('show');
                
                setTimeout(function() {
                    copyMessage.classList.remove('show');
                }, 2000);
            }).catch(function(err) {
                console.error('Falha ao copiar o texto: ', err);
            });
        });
    }
});