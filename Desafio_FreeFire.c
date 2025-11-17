// frontend/hub.js

document.addEventListener('DOMContentLoaded', () => {
    const user = JSON.parse(localStorage.getItem('user'));
    const token = localStorage.getItem('authToken');

    // 1. Segurança: Se não há usuário, volta ao login
    if (!token || !user) {
        window.location.href = 'login.html';
        return;
    }

    // 2. Referências aos elementos do menu
    const menuNav = document.getElementById('hub-menu-nav');
    const menuToggleBtn = document.getElementById('hub-menu-toggle');
    const hubMenu = document.getElementById('hub-menu');
    const icon = menuToggleBtn.querySelector('i');

    // 3. Lógica para construir o menu dinamicamente
    let menuLinks = '';
    const role = user.role;

    // Adiciona links com base na permissão
    if (role === 'admin' || role === 'Processamento') {
        menuLinks += '<a class="nav-link text-white" href="index.html"><i class="fas fa-search fa-fw me-2"></i> Processamento</a>';
    }
    if (role === 'admin' || role === 'autuador') {
        menuLinks += '<a class="nav-link text-white" href="autuacao.html"><i class="fas fa-file-alt fa-fw me-2"></i> Autuação</a>';
    }
    if (role === 'admin') {
        menuLinks += '<a class="nav-link text-white" href="admin.html"><i class="fas fa-cog fa-fw me-2"></i> Administração</a>';
        menuLinks += '<a class="nav-link text-white" href="reports.html"><i class="fas fa-chart-bar fa-fw me-2"></i> Relatórios</a>';
    }

    // Insere os links no menu
    menuNav.innerHTML = menuLinks;

    // 4. Lógica para esconder/mostrar o menu
    menuToggleBtn.addEventListener('click', () => {
        hubMenu.classList.toggle('hidden');
        
        // Alterna o ícone da seta
        if (hubMenu.classList.contains('hidden')) {
            icon.classList.remove('fa-chevron-right');
            icon.classList.add('fa-chevron-left');
        } else {
            icon.classList.remove('fa-chevron-left');
            icon.classList.add('fa-chevron-right');
        }
    });
});
