
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
            name: "giỏ hoa - hộp hoa",
            type: "select",
            options: [
                "giỏ hoa",
                "hộp hoa"
            ]
        },
        {
            name: "sinh nhật",
            type: "text"
        },
    ]

    const FLOWER_LIST = [
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        {
            name: "Love",
            price: "100.000",
            image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
        },
        
    ]

    initialMenu();
    initialFlowerList();

    function initialMenu() {
        let header = dom.getElementById("header");
        let menu = dom.createElement("ul");
        menu.className = "menu";
        MENU.forEach(item => {

            if (item.type == "text") {
                let menuLink = dom.createElement("a")
                menuLink.innerHTML = item.name;
                menuLink.href = "";
                menuLink.style.textDecoration = "none";

                let menuItem = dom.createElement("li");
                menuItem.appendChild(menuLink);
                menuItem.className = "menu-item";
                menu.appendChild(menuItem);
            } else if (item.type == "select") {
                let menuItem = dom.createElement("li");
                menuItem.innerHTML = item.name;
                menuItem.className = "menu-item";

                let subMenu = dom.createElement("ul")
                subMenu.className = "sub-menu";

                item.options.forEach(item => {
                    let subMenuItem = dom.createElement("li");
                    subMenuItem.innerHTML = item;
                    subMenuItem.href = "";

                    subMenu.appendChild(subMenuItem);
                })
                menuItem.appendChild(subMenu)
                menu.appendChild(menuItem);
            }



        })

        header.appendChild(menu)
    }


    function initialFlowerList() {

        let listContainer = dom.getElementById("list-container")

        FLOWER_LIST.forEach(flower => {
            let itemContainer = dom.createElement("div")
            itemContainer.className = "item-container"
            itemContainer.innerHTML = "abcd"

            listContainer.appendChild(itemContainer)
        }
        )


    }