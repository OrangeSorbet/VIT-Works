document.addEventListener("DOMContentLoaded", () => {
    const loginForm = document.getElementById("loginForm")
    const loginButton = loginForm.querySelector('button[type="submit"]')
  
    loginButton.addEventListener("click", function (e) {
      const rect = this.getBoundingClientRect()
      const effect = document.createElement("div")
      effect.className = "button-effect"
      effect.style.left = `${e.clientX - rect.left}px`
      effect.style.top = `${e.clientY - rect.top}px`
      this.appendChild(effect)
  
      setTimeout(() => effect.remove(), 600)
    })
  
    loginForm.addEventListener("submit", async (e) => {
      e.preventDefault()
  
      const email = document.getElementById("email").value
      const password = document.getElementById("password").value
      const remember = document.getElementById("remember").checked
  
      try {
        loginButton.disabled = true
        loginButton.innerHTML = "<span>Logging in...</span>"
  
        await new Promise((resolve) => setTimeout(resolve, 1000))
  
        const users = JSON.parse(localStorage.getItem("users") || "[]")
        const user = users.find((u) => u.email === email && u.password === password)
  
        if (user) {
          console.log("Login successful", { email, remember })
          localStorage.setItem("currentUser", JSON.stringify(user))
          window.location.href = "index.html"
        } else {
          alert("Invalid email or password")
        }
      } catch (error) {
        console.error("Login failed:", error)
      } finally {
        loginButton.disabled = false
        loginButton.innerHTML = "<span>Login</span>"
      }
    });

  document.querySelectorAll('.form-group input').forEach(input => {
      const formGroup = input.parentElement;

      input.addEventListener('focus', () => {
          formGroup.classList.add('focused');
      });

      input.addEventListener('blur', () => {
          if (!input.value) {
              formGroup.classList.remove('focused');
          }
      });

      input.addEventListener('input', () => {
          if (input.value) {
              formGroup.classList.add('has-value');
          } else {
              formGroup.classList.remove('has-value');
          }
      });

      if (input.value) {
          formGroup.classList.add('focused', 'has-value');
      }
  });
});