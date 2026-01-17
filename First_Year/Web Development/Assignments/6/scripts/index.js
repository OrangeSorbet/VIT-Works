$(document).ready(function() {
    $(window).on('scroll', function() {
        const $header = $("header");
        if ($(window).scrollTop() > 50) {
            $header.addClass('scrolled');
        } else {
            $header.removeClass('scrolled');
        }
    });

    $('a[href^="#"]').on('click', function(e) {
        e.preventDefault();
        $($(this).attr('href')).get(0).scrollIntoView({
            behavior: 'smooth'
        });
    });
});
