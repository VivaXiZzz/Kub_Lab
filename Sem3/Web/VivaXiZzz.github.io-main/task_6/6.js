window.onload = function () {
    let form = document.getElementById("form");
    let inp = document.getElementById("col");
    let r1 = document.getElementById("r1");
    let r2 = document.getElementById("r2");
    let r3 = document.getElementById("r3");
    let select = document.getElementById("goods");
    let cb1 = document.getElementById("cb1");
    let cb2 = document.getElementById("cb2");
    let cb3 = document.getElementById("cb3");
    let ptr = 0;

    function cost(id) {
        let p = inp.value;
        if (/^\d+$/.test(p) && p >= 0) {
            p = Number(p);
            let s = 0;
            let ss;
            switch (id) {
            case 1:
                s = p * r1.getAttribute("price");
                break;
            case 2:
                ss = select.options[select.selectedIndex];
                s = p * ss.getAttribute("price");
                break;
            case 3:
                s = p * r3.getAttribute("price");
                if (cb1.checked) {
                    s += p * cb1.getAttribute("price");
                }
                if (cb2.checked) {
                    s += p * cb2.getAttribute("price");
                }
                if (cb3.checked) {
                    s += p * cb3.getAttribute("price");
                }
                break;
            }
            document.getElementById("result").innerHTML = s;
        } else {
            document.getElementById("result").innerHTML = "Неверно" +
            " введено количество товаров";
        }
    }

    r1.addEventListener("click", function () {
        document.getElementById("sel").classList.add("hide");
        document.getElementById("box").classList.add("hide");
        ptr = 1;
        cost(1);
    });
    r2.addEventListener("click", function () {
        document.getElementById("sel").classList.remove("hide");
        document.getElementById("box").classList.add("hide");
        ptr = 2;
        cost(2);
    });
    r3.addEventListener("click", function () {
        document.getElementById("sel").classList.add("hide");
        document.getElementById("box").classList.remove("hide");
        ptr = 3;
        cost(3);
    });

    select.addEventListener("change", function () {
        cost(2);
    });

    cb1.addEventListener("click", function () {
        cost(3);
    });
    cb2.addEventListener("click", function () {
        cost(3);
    });
    cb3.addEventListener("click", function () {
        cost(3);
    });

    inp.addEventListener("input", function () {
        cost(ptr);
    });

    form.addEventListener("submit", function (fun) {
        fun.preventDefault();
    });
};