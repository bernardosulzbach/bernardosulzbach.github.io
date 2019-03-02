let calculatorId = "divine-orb-calculator";
let inputsId = "divine-orb-calculator-inputs";
let probabilityId = "divine-orb-calculator-probability";
let inputBaseId = "divine-orb-calculator-input";
let resultsId = "divine-orb-calculator-results";
let rollRows = 0;
let startingRows = 8;
let goalBaseId = "divine-orb-calculator-goal";
let goals = [0.5, 0.75, 0.9];

function evaluateTrialsRequired(P, p) {
    // failure after N attempts = (1 - p) ^ N
    // 1 - P = 1 - (1 - p) ^ N
    // 1 - P ≥ 1 - (1 - p) ^ N
    // log(1 - P) ≥ N log(1 - p)
    // log(1 - P) / log(1 - p) ≥ N
    // N = ceil(log(1 - P) / log(1 - p))
    return Math.ceil(Math.log(1 - P) / Math.log(1 - p));
}

function evaluate() {
    let probability = 1.0;
    for (let row = 0; row < rollRows; row++) {
        let minimum = document.getElementById(inputBaseId + "-" + row + "-minimum").value;
        let desired = document.getElementById(inputBaseId + "-" + row + "-desired").value;
        let maximum = document.getElementById(inputBaseId + "-" + row + "-maximum").value;
        if (!minimum || !maximum || !desired) {
            continue;
        }
        probability *= (maximum - desired + 1) / (maximum - minimum + 1);
    }
    document.getElementById(resultsId).innerText = "Results";
    document.getElementById(probabilityId).innerText = "Probability: " + probability.toString();
    for (let i = 0; i < goals.length; i++) {
        let goalString = "Rolls for " + Math.round(100 * goals[i]).toString() + "% chance";
        goalString += ": " + evaluateTrialsRequired(goals[i], probability);
        document.getElementById(goalBaseId + "-" + i.toString()).innerText = goalString;
    }
}

function makeInput(name, roundedLeft, roundedRight) {
    let input = document.createElement("input");
    input.id = inputBaseId + "-" + rollRows + "-" + name;
    input.type = "text";
    input.style.width = "33.33%";
    if (!roundedLeft) {
        input.style.borderTopLeftRadius = "0";
        input.style.borderBottomLeftRadius = "0";
    }
    if (!roundedRight) {
        input.style.borderTopRightRadius = "0";
        input.style.borderBottomRightRadius = "0";
    }
    input.addEventListener("keydown", function (event) {
            if (event.key === "Enter") {
                evaluate();
            }
        }
    );
    return input;
}

function addRow() {
    let minimumInput = makeInput("minimum", true, false);
    let desiredInput = makeInput("desired", false, false);
    let maximumInput = makeInput("maximum", false, true);
    minimumInput.placeholder = "Minimum";
    desiredInput.placeholder = "Desired";
    maximumInput.placeholder = "Maximum";
    let inputRow = document.createElement("div");
    inputRow.id = inputsId + "-" + rollRows.toString();
    inputRow.style.marginBottom = ".25rem";
    inputRow.appendChild(minimumInput);
    inputRow.appendChild(desiredInput);
    inputRow.appendChild(maximumInput);
    document.getElementById(inputsId).appendChild(inputRow);
    rollRows++;
}

function setUp() {
    let inputs = document.createElement("div");
    inputs.id = inputsId;
    document.getElementById(calculatorId).appendChild(inputs);
    for (let row = 0; row < startingRows; row++) {
        addRow();
    }
    let evaluateButton = document.createElement("button");
    document.getElementById(calculatorId).appendChild(evaluateButton);
    evaluateButton.innerText = "Evaluate";
    evaluateButton.onclick = evaluate;
    let results = document.createElement("h2");
    results.id = resultsId;
    document.getElementById(calculatorId).appendChild(results);
    let probability = document.createElement("p");
    probability.id = probabilityId;
    document.getElementById(calculatorId).appendChild(probability);
    for (let i = 0; i < goals.length; i++) {
        let goalElement = document.createElement("p");
        goalElement.id = goalBaseId + "-" + i.toString();
        document.getElementById(calculatorId).appendChild(goalElement);
    }
}

setUp();
