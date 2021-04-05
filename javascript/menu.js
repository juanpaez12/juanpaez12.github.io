const hamburguesa = document.querySelector('.hamburguesa');
const menu = document.querySelector('.menu');

console.log(menu);
console.log(hamburguesa);

hamburguesa.addEventListener('click', ()=>  {
    menu.classList.toggle("spread").hide(1500)
    
})
window.addEventListener('click', e=>    {
    if(menu.classList.contains('spread')
        && e.target != menu && e.target != hamburguesa){
            menu.classList.toggle('spread') 
            
                    
    }
})
