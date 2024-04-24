const dom = document;
    const MENU = [
        {
            name: "trang chủ",
            type: "text"
        },
        {
            name: "mẫu sẵn",
            type: "text"
        },
        {
            name: "bó hoa",
            type: "text"
        },
        {
            name: "sinh nhật",
            type: "text"
        },
    ]

    let cart = JSON.parse(localStorage.getItem("cart"));
    if(cart){
        cart.forEach((item, index) => {
            let tr = dom.createElement("tr");
            let td1 = createElement("td");
            let td2 = createElement("td");
            let td3 = createElement("td");
            let td4 = createElement("td");
            let td5 = createElement("td");
        })
    }
