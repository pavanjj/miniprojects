const TIMEOUT = 200;

const GREEN = 0;
const YELLOW = 1;
const RED = 2;
const BLUE = 3;

let numMoves = 0;
let level = 0;
const arrayOfMoves = [];

const greenAudio = new Audio('./sounds/green.mp3');
const yellowAudio = new Audio('./sounds/yellow.mp3');
const redAudio = new Audio('./sounds/red.mp3');
const blueAudio = new Audio('./sounds/blue.mp3');
const wrongAudio = new Audio('./sounds/wrong.mp3');
const audioArray = [greenAudio, redAudio, yellowAudio, blueAudio];

function turnOfAllClickEvents() {
    $(green).off('click');
    $(red).off('click');
    $(yellow).off('click');
    $(blue).off('click');
}
function blinkScreen() {
    $("body").addClass('game-over');
    setTimeout(() => { $("body").removeClass('game-over') }, TIMEOUT);
}
function resetTheGame() {
    turnOfAllClickEvents();
    wrongAudio.play();
    $(document).keypress(startTheGame);
    numMoves = 0;
    arrayOfMoves.length = 0;
    level = 0;
    blinkScreen();
    $("h1").text('Game Over, Press Any Key to ReStart');
}

function moveToNextLevel() {
    level++;
    const numSquares = 4;
    $("h1").text("Level " + level);
    const latestSquare = Math.floor(Math.random() * numSquares);
    animatePressAndReleaseButton(latestSquare);
    arrayOfMoves.push(latestSquare);
    numMoves = 0;
}

function checkNextMove(nextMoveId) {
    return nextMoveId === arrayOfMoves[numMoves];
}
function advanceGame(nextMoveId) {
    if (checkNextMove(nextMoveId)) {
        numMoves++;
        if (numMoves === arrayOfMoves.length)
            setTimeout(() => { moveToNextLevel() }, TIMEOUT * 3);
    } else {
        resetTheGame();
    }
}
function animatePressAndReleaseButton(squareId) {
    switch (squareId) {
        case GREEN: animateGreenButton();
            break;
        case RED: animateRedButton();
            break;
        case YELLOW: animateYellowButton();
            break;
        case BLUE: animateBlueButton();
            break;
    }
}
function setUnpressCallback(callback) {
    setTimeout(callback, TIMEOUT);
}
function animateGreenButton() {
    $(green).addClass('pressed');
    greenAudio.play();
    setUnpressCallback(() => { $(green).removeClass('pressed'); });
}
function animateRedButton() {
    $(red).addClass('pressed');
    redAudio.play();
    setUnpressCallback(() => { $(red).removeClass('pressed'); });
}
function animateYellowButton() {
    $(yellow).addClass('pressed');
    yellowAudio.play();
    setUnpressCallback(() => { $(yellow).removeClass('pressed'); });
}
function animateBlueButton() {
    $(blue).addClass('pressed');
    blueAudio.play();
    setUnpressCallback(() => { $(blue).removeClass('pressed'); });
}

function startTheGame() {
    $(document).off('keypress');
    $(green).on('click', () => {
        animateGreenButton();
        advanceGame(GREEN);
    });
    $(red).on('click', () => {
        animateRedButton();
        advanceGame(RED);
    });
    $(yellow).on('click', () => {
        animateYellowButton();
        advanceGame(YELLOW);
    });
    $(blue).on('click', () => {
        animateBlueButton();
        advanceGame(BLUE);
    });
    moveToNextLevel();
}
$(document).keypress(startTheGame);
