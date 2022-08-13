function openNav() {
    document.getElementById("mySidenav").style.width = "300px";
}

function closeNav() {
    document.getElementById("mySidenav").style.width = "0";
}

function openImage() {
    document.getElementByTagName("img").style.textAlign = "center";
    document.getElementByTagName("img").style.margin = "auto";
    document.getElementByTagName("img").style.display = "block";
    document.getElementByTagName("img").style.width = "60%";
}
// document.addEventListener('DOMContentLoaded', function {
//     document.querySelector('.images').addEventListener('click', function {
//         document.body.style.backgroundColor = hsl(0, 0%, 50%);
//     });
// });