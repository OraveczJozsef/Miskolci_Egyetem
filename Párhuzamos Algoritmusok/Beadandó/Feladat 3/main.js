const settings = {
    width: 80,
    height: 40,
    colors: 30,
    draw_time: 0.000000000000000000000000000000000000000000001,
    palette: [
        '#fff',
        '#fff',
        '#fff',
        '#fff',
        '#fff',
        '#fff',
        '#fff',
        '#fff',
        '#fff',
        '#ff0',
        '#ff0',
        '#fe0',
        '#fe0',
        '#fd0',
        '#fd0',
        '#fc0',
        '#fb0',
        '#f90',
        '#f70',
        '#f50',
        '#f30',
        '#f10',
        '#e00',
        '#c00',
        '#a00',
        '#800',
        '#600',
        '#400',
        '#200',
        '#000'
    ]
};
const sleep = ms => new Promise(r => setTimeout(r, ms));

let matrix = new Array();
let step = 0;
let is_run = false;

function init_matrix() {
    let place = document.getElementById('fireplace');

    for (let y = 0, y_lengrh = settings.height; y <= y_lengrh; y++) {
        matrix[y] = new Array();

        for (let x = 0; x < settings.width; x++) {
            matrix[y][x] = {
                color: settings.colors - 1
            };

            if (y < settings.height) {
                let ember = document.createElement('div');

                ember.id = "matrix_x" + x + "y" + y;
                ember.className = "ember";

                place.appendChild(ember);

                matrix[y][x].ember = document.getElementById('matrix_x' + x + 'y' + y);
            }
        }
    }
}

async function matrix_run() {
    //console.log("[Main] Start ...");
    step++;
    if (step >= 2) {
        step = 0;
    }

    for (let y = settings.height; y >= 0; y--) {
        draw_line(y);

        //await sleep(settings.draw_time);
    }

    await sleep(30);

    //console.log("[Main] Ready ...");
    if (is_run) {
        matrix_run();
    }
}

async function draw_line(y) {
    console.log("[Y: " + y + "] Draw line...");
    await sleep(settings.draw_time);

    for (let x = 0; x < settings.width; x++) {
        if (y == settings.height) {
            if (step == 0) {
                matrix[y][x].color = Math.floor(Math.random() * settings.colors);
            }
        } else {
            let new_color = 0;

            if ((x > 0) && (x < (settings.width - 1))) {
                new_color += matrix[y][x - 1].color;
                new_color += matrix[y][x + 1].color;
                new_color += matrix[y + 1][x - 1].color;
                new_color += matrix[y + 1][x + 1].color;
            } else {
                if (x == 0) {
                    new_color += matrix[y][x + 1].color;
                    new_color += matrix[y + 1][x + 1].color;
                } else {
                    new_color += matrix[y][x - 1].color;
                    new_color += matrix[y + 1][x - 1].color;
                }

                new_color += ((settings.colors - 1) * 2);
            }

            new_color += matrix[y][x].color;
            new_color += (matrix[y + 1][x].color * 2);

            new_color = Math.round(new_color / 6.8);

            if (new_color > settings.colors) {
                new_color = settings.colors - 1;
            }

            matrix[y][x].color = new_color;
        }

        if (y < settings.height) {
            matrix[y][x].ember.style.backgroundColor = settings.palette[matrix[y][x].color];
        }
    }
    console.log("[Y: " + y + "] Success...");
}

function start() {
    if (!is_run) {
        is_run = true;

        init_matrix();
        matrix_run();
    }
}

function stop() {
    if (is_run) {
        is_run = false;
    }
}

start();

/*
async function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function worker1() {
    console.log("[1] Start ...");
    await sleep(2000);
    console.log("[1] Ready!");
}

async function worker2() {
    console.log("[2] Start ...");
    await sleep(3000);
    console.log("[2] Ready!");
}

async function worker3() {
    console.log("[3] Start ...");
    await sleep(1000);
    console.log("[3] Ready!");
}

async function sample() {
    worker1();
    worker2();
    worker3();
}

sample()
*/