let slideIndex = 1;
showSlides(slideIndex);

// Auto slide show function
function autoSlideShow() {
    plusSlides(1); // Move to the next slide
}

// Function to move to the next slide
function plusSlides(n) {
    showSlides(slideIndex += n);
}

// Function to set the current slide
function currentSlide(n) {
    showSlides(slideIndex = n);
}

// Function to show the slides
function showSlides(n) {
    let slides = document.getElementsByClassName("mySlides");
    let dots = document.getElementsByClassName("dot");

    if (slides.length === 0) {
        console.error("No slides found. Ensure that the HTML contains elements with class 'mySlides'.");
        return;
    }

    if (n > slides.length) { slideIndex = 1; }
    if (n < 1) { slideIndex = slides.length; }

    for (let i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";
    }

    for (let i = 0; i < dots.length; i++) {
        dots[i].className = dots[i].className.replace(" active", "");
    }

    if (slides[slideIndex - 1]) {
        slides[slideIndex - 1].style.display = "block";
        dots[slideIndex - 1].className += " active";
    }
}


// Set interval to auto slide every 3 seconds (3000 milliseconds)
window.onload = function () {
    let slideIndex = 1;
    showSlides(slideIndex);
    setInterval(autoSlideShow, 3000);
};
