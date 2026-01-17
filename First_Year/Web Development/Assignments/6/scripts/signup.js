document.addEventListener("DOMContentLoaded", () => {
    const signupForm = document.getElementById("signupForm")
    const signupButton = signupForm.querySelector('button[type="submit"]')
  
    signupButton.addEventListener("click", function (e) {
      const rect = this.getBoundingClientRect()
      const effect = document.createElement("div")
      effect.className = "button-effect"
      effect.style.left = `${e.clientX - rect.left}px`
      effect.style.top = `${e.clientY - rect.top}px`
      this.appendChild(effect)
  
      setTimeout(() => effect.remove(), 600)
    })
  
    signupForm.addEventListener("submit", async (e) => {
      e.preventDefault()
      sendMail()
    })
})
  
    function sendMail() {
        const name = document.getElementById("name").value
        const email = document.getElementById("email").value
        const password = document.getElementById("password").value
        const confirmPassword = document.getElementById("confirmPassword").value
        const terms = document.getElementById("terms").checked


        const users = JSON.parse(localStorage.getItem("users")) || []
        const existingUser = users.find((user) => user.email === email)
      

        if (password !== confirmPassword) {
            alert("Passwords do not match!")
            return
        }
      
        if (!terms) {
            alert("Please accept the Terms & Conditions")
            return
        }

        if (existingUser) {
            alert("User with this email already exists please Login!")
            window.location.href = "login.html"
            return
        }
        
      
        var params = {
          name: name,
          mail: email,
        }
      
        const serviceID = "service_w041eco"
        const templateID = "template_77uu31o"
      
        emailjs
          .send(serviceID, templateID, params)
          .then((res) => {
            document.getElementById("name").value = ""
            document.getElementById("email").value = ""
            console.log(res)
            alert("You Have Successfully Registered for Veloce, Check Your Mail!")
      
            users.push({ name, email, password })
            localStorage.setItem("users", JSON.stringify(users))
            window.location.href = "login.html"
          })
          .catch((err) => {
            console.log(err)
            alert("There was an error sending your application. Please try again later.")
          })
      }