function openNav() {
    document.getElementById("mySidenav").style.width = "300px";
}

function closeNav() {
    document.getElementById("mySidenav").style.width = "0";
}

function openImage() {
    document.querySelector("img").classList.add('position-absolute', 'top-50', 'start-0', 'translate-middle');
    document.querySelector("img").style.objectFit = "scale-down";
    document.querySelector("body").style.backgroundColor = "#808080";
}