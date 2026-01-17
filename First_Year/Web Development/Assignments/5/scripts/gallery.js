document.addEventListener('DOMContentLoaded', function () {
    function animateGalleryItems() {
        const galleryItems = document.querySelectorAll('.gallery-item');
        galleryItems.forEach(function (item, i) {
            const itemPosition = item.getBoundingClientRect().top + window.pageYOffset;
            const scrollPosition = window.scrollY + window.innerHeight;

            if (scrollPosition > itemPosition) {
                item.classList.add('fade-in');
                item.style.animationDelay = `${i * 0.1}s`;
            }
        });
    }

    animateGalleryItems();

    window.addEventListener('scroll', function () {
        animateGalleryItems();
    });
});
