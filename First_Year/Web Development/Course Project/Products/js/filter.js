document.addEventListener('DOMContentLoaded', function() {
    const categoryToggles = document.querySelectorAll('.category-toggle');
    
    categoryToggles.forEach(toggle => {
        toggle.addEventListener('change', function() {
            const subcategories = this.nextElementSibling.nextElementSibling;
            if (this.checked) {
                subcategories.style.maxHeight = subcategories.scrollHeight + "px";
            } else {
                subcategories.style.maxHeight = 0;
            }
        });
    });

    let favorites = JSON.parse(localStorage.getItem('favorites')) || [];

    const heartIcons = document.querySelectorAll('.heart-red');
    
    heartIcons.forEach(heart => {
        const itemContainer = heart.closest('.item-cont');
        const itemData = {
            image: itemContainer.querySelector('.image-cont img:not(.heart-red)').src,
            description: itemContainer.querySelector('.img-desc p').textContent
        };
        
        if (favorites.some(fav => fav.description === itemData.description)) {
            heart.classList.add('active');
        }

        heart.addEventListener('click', function(e) {
            e.preventDefault();
            this.classList.toggle('active');

            if (this.classList.contains('active')) {
                if (!favorites.some(fav => fav.description === itemData.description)) {
                    favorites.push(itemData);
                    showNotification('Added to favorites!');
                }
            } else {
                favorites = favorites.filter(fav => fav.description !== itemData.description);
                showNotification('Removed from favorites');
            }

            localStorage.setItem('favorites', JSON.stringify(favorites));
        });
    });
});

function showNotification(message) {
    const notification = document.createElement('div');
    notification.className = 'notification';
    notification.textContent = message;
    document.body.appendChild(notification);

    setTimeout(() => {
        notification.remove();
    }, 2000);
}