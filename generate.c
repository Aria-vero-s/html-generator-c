function processCommand(command) {
  const output = document.getElementById('output');
  
  const args = command.split(' ');
  const mainCommand = args[0];
  const parameters = args.slice(1).join(' '); // Récupère tous les paramètres après la commande

  if (mainCommand === 'help') {
    output.innerHTML += '<div>$ help</div><div>Voici les commandes disponibles:</div><div>- greet [nom]: Affiche un message de bienvenue</div><div>- help: Affiche les instructions</div>';
  } else if (mainCommand === 'greet') {
    if (parameters) {
      output.innerHTML += `<div>$ greet ${parameters}</div><div>Bonjour, ${parameters} ! Bienvenue sur le terminal simulé.</div>`;
    } else {
      output.innerHTML += '<div>$ greet</div><div>Vous devez entrer un nom après "greet". Exemple: "greet Alice".</div>';
    }
  } else {
    output.innerHTML += `<div>$ ${command}</div><div>Commande inconnue. Tapez "help" pour voir les options.</div>`;
  }
  output.scrollTop = output.scrollHeight;
}
