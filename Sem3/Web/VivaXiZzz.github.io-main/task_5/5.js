window.onload = function () {
  document.getElementById("for").addEventListener("submit", function (fun) 
  {
    fun.preventDefault();
    let amount = document.getElementById("amount").value;
    let goood = document.getElementById("goood");
    let elementprice = goood.options[goood.selectedIndex];
    let price = elementprice.getAttribute("Price");
    let namel = goood.options[goood.selectedIndex];
    let name = namel.getAttribute("a");
    if (/^\d+$/.test(amount) && amount >= 0) {
      amount = Number(amount);
      document.getElementById("result").innerHTML = amount * price + " " + name;
    } else {
      document.getElementById("result").innerHTML = "Введите кол-во товаров";
    }
  });
};

