
let greenPoints = localStorage.getItem("greenPoints");
let actionsCompleted = localStorage.getItem("actionsCompleted");

// Points set to 0 when no data is there
greenPoints = greenPoints ? Number(greenPoints) : 0;
actionsCompleted = actionsCompleted ? Number(actionsCompleted) : 0;

const pointsEl = document.getElementById("points");
const actionsEl = document.getElementById("actions");
const levelEl = document.getElementById("level");

// dark mode logic
const savedTheme = localStorage.getItem("theme");

if (savedTheme === "dark") {
  document.body.classList.add("dark");
}

const themeToggleBtn = document.getElementById("themeToggleBtn");

function toggleDarkMode() {
  document.body.classList.toggle("dark");

  if (document.body.classList.contains("dark")) {
    localStorage.setItem("theme", "dark");
    themeToggleBtn.textContent = "☀️ Light Mode";
  } else {
    localStorage.setItem("theme", "light");
    themeToggleBtn.textContent = "🌙 Dark Mode";
  }
}

// disable addSelectedAction
const ecoSelect = document.getElementById("ecoAction");
const addActionBtn = document.getElementById("addActionBtn");

ecoSelect.addEventListener("change", () => {
  addActionBtn.disabled = ecoSelect.value === "";
});

// Giving Username
let userName = localStorage.getItem("userName");

const nameScreen = document.getElementById("nameScreen");
const mainApp = document.getElementById("mainApp");
const welcomeText = document.getElementById("welcomeText");

// decide which screen to show
if (userName) {
  nameScreen.style.display = "none";
  mainApp.style.display = "block";
  greetUser();
} else {
  nameScreen.style.display = "flex";
  mainApp.style.display = "none";
}

function saveUserName() {
  const input = document.getElementById("userNameInput").value.trim();

  if (input === "") {
    alert("Please enter your name 🌱");
    return;
  }

  userName = input;
  localStorage.setItem("userName", userName);

  nameScreen.style.display = "none";
  mainApp.style.display = "block";
  greetUser();
}

function changeUser() {
  const confirmChange = confirm(
    "Do you want to change the user?\nYour current progress will be reset."
  );

  if (!confirmChange) return;

  // reset wallet values
  greenPoints = 0;
  actionsCompleted = 0;

  // clear localStorage completely
  localStorage.removeItem("userName");
  localStorage.removeItem("greenPoints");
  localStorage.removeItem("actionsCompleted");

  updateDashboard();

  mainApp.style.display = "none";
  nameScreen.style.display = "flex";

  document.getElementById("userNameInput").value = "";
}

function greetUser() {
  if (welcomeText && userName) {
    welcomeText.textContent = `Welcome, ${userName} 👋`;
  }
}

// Add points
function addPoints(points) {
  greenPoints += points;
  actionsCompleted++;

  localStorage.setItem("greenPoints", greenPoints);
  localStorage.setItem("actionsCompleted", actionsCompleted);

  updateDashboard();
}

function addSelectedAction() {
  const select = document.getElementById("ecoAction");
  const value = select.value;

  if (value === "") {
    alert("Please select an eco action first 🌱");
    return;
  }

 addPoints(Number(value));
select.value = "";
addActionBtn.disabled = true; 
}

function resetWallet() {
  const confirmReset = confirm(
    "Are you sure you want to reset your Green Wallet?\nThis action cannot be undone."
  );

  if (!confirmReset) return;

  // reset values
  greenPoints = 0;
  actionsCompleted = 0;

  // clear localStorage
  localStorage.setItem("greenPoints", 0);
  localStorage.setItem("actionsCompleted", 0);

  updateDashboard();
}

// Level of user
function getImpactLevel() {
  if (greenPoints === 0) {
    return "Just Getting Started";
  } else if (greenPoints < 50) {
    return "Eco-Beginner 🌱";
  } else if (greenPoints < 150) {
    return "Green Enthusiast 🌿";
  } else if (greenPoints < 300) {
    return "Environmental Champion 🌍";
  } else {
    return "Planet Protector 🌎";
  }
}

function updateDashboard() {
  pointsEl.textContent = greenPoints;
  actionsEl.textContent = actionsCompleted;
  levelEl.textContent = getImpactLevel();
}

// Eco Actions
function paidBillsDigitally() {
  addPoints(10);
}

function usedPublicTransport() {
  addPoints(20);
}

function avoidedPlastic() {
  addPoints(15);
}

function usedSolarEnergy() {
  addPoints(30);
}

function wentCarpooling() {
  addPoints(25);
}

function cycledOrWalked() {
  addPoints(20);
}

function switchedOffAppliances() {
  addPoints(10);
}

function usedEfficientDevices() {
  addPoints(25);
}

function plantedTree() {
  addPoints(50);
}

function paperlessBanking() {
  addPoints(15);
}

updateDashboard();
