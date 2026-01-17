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





//categories filter
document.addEventListener('DOMContentLoaded', function () {
    const checkboxes = document.querySelectorAll('.subcategory input[type="checkbox"]');
    const productItems = document.querySelectorAll('.item-cont');

    checkboxes.forEach(checkbox => {
        checkbox.addEventListener('change', filterProducts);
    });

    function filterProducts() {
        // Get all selected filters (trimmed & lowercase)
        let selectedFilters = Array.from(checkboxes)
            .filter(checkbox => checkbox.checked)
            .map(checkbox => checkbox.parentNode.textContent.trim().toLowerCase());

        productItems.forEach(item => {
            let category = (item.dataset.category || "").toLowerCase().trim();

            // Show all products if no filters are selected
            if (selectedFilters.length === 0 || selectedFilters.some(filter => category.includes(filter))) {
                item.style.display = 'block';
            } else {
                item.style.display = 'none';
            }
        });
    }
});
