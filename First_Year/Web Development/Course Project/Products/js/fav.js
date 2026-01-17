document.addEventListener("DOMContentLoaded", () => {
    const favoritesGrid = document.getElementById("favorites-grid")
    let favorites = JSON.parse(localStorage.getItem("favorites")) || []
  
    function renderFavorites() {
      favoritesGrid.innerHTML = ""
  
      if (favorites.length === 0) {
        favoritesGrid.innerHTML = `
                  <div class="empty-favorites">
                      <img src="https://www.svgrepo.com/show/532473/heart.svg" alt="Empty favorites">
                      <p>Your favorites list is empty</p>
                      <a href="browse.html" class="browse-button">Browse Products</a>
                  </div>
              `
      } else {
        favorites.forEach((item) => {
          const itemElement = document.createElement("div")
          itemElement.className = "item-cont"
          itemElement.innerHTML = `
                      <div class="image-cont">
                          <img src="https://www.svgrepo.com/show/532473/heart.svg" class="heart-red active" alt="Remove from favorites">
                          <img src="${item.image}" alt="${item.description}">
                          <div class="img-desc">
                              <p>${item.description}</p>
                          </div>
                      </div>
                  `
  
          const heartIcon = itemElement.querySelector(".heart-red")
          heartIcon.addEventListener("click", () => {
            favorites = favorites.filter((fav) => fav.description !== item.description)
            localStorage.setItem("favorites", JSON.stringify(favorites))
            renderFavorites()
            showNotification("Removed from favorites")
          })
  
          favoritesGrid.appendChild(itemElement)
        })
      }
    }
  
    renderFavorites()
  
    window.addEventListener("storage", (e) => {
      if (e.key === "favorites") {
        favorites = JSON.parse(e.newValue) || []
        renderFavorites()
      }
    })
  })
  
  function showNotification(message) {
    const notification = document.createElement("div")
    notification.className = "notification"
    notification.textContent = message
    document.body.appendChild(notification)
  
    setTimeout(() => {
      notification.remove()
    }, 2000)
  }
  
  