function openNav() {
    document.getElementById("mySidenav").style.width = "300px";
}

function closeNav() {
    document.getElementById("mySidenav").style.width = "0";
}

function openImage() {
    document.getElementByTagName("div img").classList.add('position-fixed top-50 start-0 translate-middle');
}

// document.addEventListener('DOMContentLoaded', function {
//     document.querySelector('.images').addEventListener('click', function {
//         document.body.style.backgroundColor = hsl(0, 0%, 50%);
//     });
// });