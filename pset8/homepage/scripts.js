function openNav() {
    document.getElementById("mySidenav").style.width = "300px";
}

function closeNav() {
    document.getElementById("mySidenav").style.width = "0";
}

function openImage() {
    document.getElementById("img").classList.add('position-fixed top-50 start-0 translate-middle');
    document.getElementById("img").style.objectFit = "scale-down";
}

// document.addEventListener('DOMContentLoaded', function {
//     document.querySelector('.images').addEventListener('click', function {
//         document.body.style.backgroundColor = hsl(0, 0%, 50%);
//     });
// });