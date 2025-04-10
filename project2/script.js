const API_URL = 'http://localhost:3000';

async function getBalance() {
  const res = await fetch(`${API_URL}/balance`);
  const data = await res.json();
  document.getElementById("balance").innerText = data.balance;
}

async function placeBet(choice) {
  document.getElementById("result").innerText = "Fighting...";
  
  try {
    const res = await fetch(`${API_URL}/bet`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ choice })
    });

    const data = await res.json();
    document.getElementById("result").innerText =
      data.result === "WIN"
        ? `🎉 You WON! ${data.winner} wins!`
        : `😢 You LOST! ${data.winner} wins!`;

    document.getElementById("balance").innerText = data.balance;

  } catch (err) {
    alert("Error placing bet: " + err.message);
    }
}

// Fetch initial balance when page loads
window.onload = getBalance;