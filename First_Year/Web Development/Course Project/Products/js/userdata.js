document.addEventListener("DOMContentLoaded", () => {
    const signupForm = document.getElementById("signupForm")
    const loginForm = document.getElementById("loginForm")
  
    if (signupForm) {
      signupForm.addEventListener("submit", (event) => {
        event.preventDefault()
        sendMail()
      })
    }
  
    if (loginForm) {
      loginForm.addEventListener("submit", (event) => {
        event.preventDefault()
        login()
      })
    }
  })
  
  function sendMail() {
    const name = document.getElementById("fname").value
    const email = document.getElementById("email").value
    const password = document.getElementById("password").value
  
    const users = JSON.parse(localStorage.getItem("users")) || []
    const existingUser = users.find((user) => user.email === email)
  
    if (existingUser) {
      alert("User with this email already exists!")
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
        document.getElementById("fname").value = ""
        document.getElementById("email").value = ""
        console.log(res)
        alert("You Have Successfully Registered for Synercom, Check Your Mail!")
  
        users.push({ name, email, password })
        localStorage.setItem("users", JSON.stringify(users))
        window.location.href = "login.html"
      })
      .catch((err) => {
        console.log(err)
        alert("There was an error sending your application. Please try again later.")
      })
  }
  
  function login() {
    const email = document.getElementById("email").value
    const password = document.getElementById("password").value
  
    const users = JSON.parse(localStorage.getItem("users")) || []
    const user = users.find((user) => user.email === email && user.password === password)
  
    if (user) {
      alert("Login successful!")
      window.location.href = "home.html"
    } else {
      alert("Invalid email or password!")
    }
  }
  
  