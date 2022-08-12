function openNav() {
    document.getElementById("mySidenav").style.width = "300px";
    if (window.matchMedia("(max-width: < 450px)")) {
        document.getElementById("mySidenav").style.width = "100%";
    }
}

function closeNav() {
    document.getElementById("mySidenav").style.width = "0";
}