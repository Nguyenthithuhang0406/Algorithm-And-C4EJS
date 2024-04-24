const dom = document;
const MENU = [
    {
        name: "TRANG CHỦ",
        type: "text"
    },
    {
        name: "MẪU SẴN",    
        type: "text"
    },
    {
        name: "BÓ HOA",
        type: "text"
    },
    // {
    //     name: "GIỎ HOA - HỘP HOA",
    //     type: "Select",
    //     options: [
    //         "Giỏ hoa",
    //         "Hộp hoa"
    //     ]
    // },
    // {
    //     name: "HOA SINH NHẬT",
    //     type: "Select",
    //     options: [
    //         "Gía dưới 300.000đ",
    //         "Sinh nhật ba mẹ",
    //         "Sinh nhật người yêu",
    //         "Sinh nhật vợ chồng",
    //         "Sinh nhật đồng nghiệp"
    //     ]
    // },
    {
        name: "HOA SÁP",
        type: "text"
    },
    {
        name: "HOA CHÚC MỪNG",
        type: "text"
    },
    {
        name: "HOA CHIA BUỒN",
        type: "text"
    },
    {
        name: "LAN HỒ ĐIỆP",
        type: "text"
    },
    {
        name: "GIỎ TRÁI CÂY",
        type: "text"
    },
    // {
    //     name: "LOẠI HOA",
    //     type: "Select",
    //     options: [
    //         "Bó hoa bi",
    //         "Bó hoa cẩm chướng",
    //         "Bó hoa cát tường",
    //         "Bó hoa cúc",
    //         "Bó hoa hồng",
    //         "Bó hoa hướng dương",
    //         "Bó hoa lan",
    //         "Bó hoa lan hồ điệp",
    //         "Bó hoa ly",
    //         "Bó hoa đồng tiền",
    //         "Các loài hoa"
    //     ]
    // },
    // {
    //     name: "CÂY XANH VĂN PHÒNG",
    //     type: "Select",
    //     options: [
    //         "Cây để bàn",
    //         "Cây cho phòng khách",
    //         "Cây khai trương"
    //     ]
    // },
    {
        name: "HOA CƯỚI",
        type: "text"
    }
]

const FLOWER_LIST = [
    {
        name: "Love",
        price: "300.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/193/300_1/jpg/love_300x300.jpg"
    },
    {
        name: "Bó hoa hồng trắng + Baby trắng",
        price: "390.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/366/300_1/jpg/bo-hoa-hong-trang-baby-trang_300x300.jpg"
    },
    {
        name: "Baby girl",
        price: "300.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/836/300_1/jpg/baby-girl_300x300.jpg"
    },
    {
        name: "Bó hoa cúc Tana",
        price: "280.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/107/300_1/jpg/bo-hoa-cuc-tana_300x300.jpg"
    },
    {
        name: "Bó hoa hồng 7 bông kèm phụ kiện",
        price: "300.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/105/300_1/jpg/bo-hoa-hong-7-bong-kem-phu-kien_300x300.jpg"
    },
    {
        name: "Tình hồng",
        price: "300.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/819/300_1/jpg/tinh-hong_300x300.jpg"
    },
    {
        name: "Bó hoa hướng dương phối baby trắng",
        price: "350.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/262/300_1/jpg/bo-hoa-huong-duong-phoi-baby-trang_300x300.jpg" 
    },
    {
        name: "Bó hoa hồng kem phối bi trắng đẹp",
        price: "300.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/106/300_1/jpg/bo-hoa-hong-kem-phoi-bi-trang-dep_300x300.jpg"
    },
    {
        name: "Cô bé mùa đông",
        price: "250.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/822/300_1/jpg/co-be-mua-dong_300x300.jpg"
    },
    {
        name: "Bó hoa hồng đỏ rạng ngời",
        price: "660.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/364/300_1/jpg/bo-hoa-hong-do-rang-ngoi_300x300.jpg"
    },
    {
        name: "Màu tình yêu",
        price: "2.200.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/189/300_1/jpg/mau-tinh-yeu_300x300.jpg"
    },
    {
        name: "Bó Hoa Pink",
        price: "420.000 VND",
        image: "https://hoathuongyeu.com.vn/files/sanpham/363/300_1/jpg/bo-hoa-pink_300x300.jpg"
    }
]

let cart = [];

// if(localStorage.getItem("cart")){
//     cart = JSON.parse(localStorage.getItem("cart"));
//     document.getElementById("product-number").innerHTML = cart.length;
// }

initialMenu();
initialFlowerList();

function initialMenu() {
    let header = dom.getElementById("header");
    let menu = dom.createElement("ul");
    menu.className = "menu";
    MENU.forEach(item => {

        if (item.type == "text") {
            let menuLink = dom.createElement("a");
            menuLink.innerHTML = item.name;
            menuLink.href = "";
            menuLink.style.textDecoration = "none";

            let menuItem = dom.createElement("li");
            menuItem.appendChild(menuLink);
            menuItem.className = "menu-item";
            menu.appendChild(menuItem);
        } 
        //  else if (item.type == "Select") {
        //      let menuItem = dom.createElement("li");
        //     menuItem.innerHTML = item.name;
        //      menuItem.className = "menu-item";

        //     let subMenu = dom.createElement("ul");
        //      subMenu.className = "sub-menu";

        //      item.options.forEach(item => {
        //          let subMenuItem = dom.createElement("li");
        //          subMenuItem.innerHTML = item;
        //          subMenuItem.href = "";

        //         subMenu.appendChild(subMenuItem);
        //     })
        //     menuItem.appendChild(subMenu);
        //     menu.appendChild(menuItem);
        //  }



    })

    header.appendChild(menu);
}


function initialFlowerList() {

    let listContainer = dom.getElementById("list-container");

    FLOWER_LIST.forEach(flower => {
        let itemContainer = dom.createElement("div");
        itemContainer.className = "item-container";
       let img = dom.createElement("img");
       img.src = flower.image;
        img.width = "180";
        img.height = "200";
       
       let name = dom.createElement("p");
       name.innerHTML = flower.name;
       let price = dom.createElement("p");
       price.innerHTML = flower.price;

       let btnAddToCart = dom.createElement("button");
       btnAddToCart.innerHTML = "Thêm vào giỏ hàng";
       btnAddToCart.className = "btn-add-to-cart";
       btnAddToCart.addEventListener("click", () => {
            cart.push(flower);
            localStorage.setItem("cart", JSON.stringify(cart));
            document.getElementById("product-number").innerHTML = cart.length;
       })

       itemContainer.appendChild(img);
       itemContainer.appendChild(name);
       itemContainer.appendChild(price);
       itemContainer.appendChild(btnAddToCart);

        listContainer.appendChild(itemContainer);
    }
    )


}