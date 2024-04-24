function summ(a, b){
    return a+b;
}

function tich(a,b){
    return a*b;
}

function thuong(a,b){
    if(b != 0){
        return a/ b;
    }else{
        return "Không thể chia";
    }
}

export {
    summ,
    tich,
    thuong
};