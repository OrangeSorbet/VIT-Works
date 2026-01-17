(function(){

    let inputContainer = document.querySelector(".input-container");
    let input = inputContainer.firstElementChild.nextElementSibling;
    let minus = inputContainer.firstElementChild;
    let plus = inputContainer.lastElementChild;
  
    function changeNumber(e) {
        if(e.target == minus) {
            input.value--;
        } else if(e.target == plus) {
            input.value++;
        }
    }
  
    inputContainer.addEventListener("click", changeNumber);
  })();