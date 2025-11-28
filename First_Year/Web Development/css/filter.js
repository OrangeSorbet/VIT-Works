// test.js

// Array to store the confetti colors for VIBGYOR
const colors = ['violet', 'indigo', 'blue', 'green', 'yellow', 'orange', 'red'];

const searchBar = document.querySelector('.search-bar input');

// Function to generate confetti from random positions on the search bar
function createConfetti(event) {
    // Create confetti element
    const confetti = document.createElement('div');
    confetti.classList.add('confetti');

    // Randomly pick a color from the VIBGYOR array
    const color = colors[Math.floor(Math.random() * colors.length)];
    confetti.style.backgroundColor = color;

    // Calculate a random position along the width of the search bar
    const searchBarRect = searchBar.getBoundingClientRect();
    const randomX = Math.random() * searchBarRect.width + searchBarRect.left;
    const randomY = searchBarRect.top + searchBarRect.height / 2; // Place it slightly below the search bar for more natural effect

    // Apply random position
    confetti.style.left = `${randomX - 5}px`;  // Adjust for confetti size
    confetti.style.top = `${randomY - 5}px`;  // Center vertically within the search bar

    // Append the confetti to the body
    document.body.appendChild(confetti);

    // Remove the confetti after the animation completes (3s)
    setTimeout(() => {
        confetti.remove();
    }, 3000); // The duration should match the falling animation time
}

// Event listener for typing in the search bar
searchBar.addEventListener('input', (event) => {
    createConfetti(event);
});

// Event listener for mouse move (to create confetti when typing)
searchBar.addEventListener('mousemove', (event) => {
    createConfetti(event);
});
