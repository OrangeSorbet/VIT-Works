$(document).ready(function() {
    function animateGalleryItems() {
        $('.gallery-item').each(function(i) {
            const itemPosition = $(this).offset().top;
            const scrollPosition = $(window).scrollTop() + $(window).height();

            if (scrollPosition > itemPosition) {
                $(this).addClass('fade-in');
                $(this).css('animation-delay', `${i * 0.1}s`);
            }
        });
    }

    animateGalleryItems();
    $(window).scroll(function() {
        animateGalleryItems();
    });
});