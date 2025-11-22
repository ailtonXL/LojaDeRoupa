document.addEventListener('DOMContentLoaded', function() {
    const carousel = document.querySelector('.image-carousel');
    const carouselItems = document.querySelectorAll('.carousel-item');
    const prevBtn = document.querySelector('.prev-btn');
    const nextBtn = document.querySelector('.next-btn');
    let currentIndex = 0;
    const itemWidth = carouselItems[0].clientWidth; // Largura de um item do carrossel

    // Função para atualizar a exibição do carrossel
    function updateCarousel() {
        carousel.style.transform = `translateX(${-currentIndex * itemWidth}px)`;
    }

    // Evento para o botão Anterior
    prevBtn.addEventListener('click', function() {
        currentIndex--;
        if (currentIndex < 0) {
            currentIndex = carouselItems.length - 1; // Volta para a última imagem
        }
        updateCarousel();
    });

    // Evento para o botão Próximo
    nextBtn.addEventListener('click', function() {
        currentIndex++;
        if (currentIndex >= carouselItems.length) {
            currentIndex = 0; // Volta para a primeira imagem
        }
        updateCarousel();
    });

    // Para a passagem automática das fotos
    let autoSlideInterval = setInterval(function() {
        currentIndex++;
        if (currentIndex >= carouselItems.length) {
            currentIndex = 0;
        }
        updateCarousel();
    }, 5000); // Mude 5000 para o tempo em milissegundos que deseja (5 segundos neste caso)

    // Opcional: Pausar o autoslide ao passar o mouse e reiniciar ao tirar
    carousel.addEventListener('mouseenter', function() {
        clearInterval(autoSlideInterval);
    });

    carousel.addEventListener('mouseleave', function() {
        autoSlideInterval = setInterval(function() {
            currentIndex++;
            if (currentIndex >= carouselItems.length) {
                currentIndex = 0;
            }
            updateCarousel();
        }, 5000);
    });

    // Ajustar o carrossel se a janela for redimensionada
    window.addEventListener('resize', function() {
        // Recalcula a largura do item para garantir que a translação esteja correta
        const newItemWidth = carouselItems[0].clientWidth;
        carousel.style.transform = `translateX(${-currentIndex * newItemWidth}px)`;
    });
});