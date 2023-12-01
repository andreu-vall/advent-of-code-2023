readline = require('readline')

//Couldn't even get the data with synchronous stdin: prompy-sync invented lines and fs.readFileSync(0) only read 4098 Bytes...
const reader = readline.createInterface({input: process.stdin, output: process.stdout, terminal: false})

var suma = 0
var suma2 = 0

spelled = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']

reader.on('line', line => {
    var real_digits = []
    for (var i = 0; i < line.length; i++) {
        if (line[i] >= '0' && line[i] <= '9') {
            real_digits.push(parseInt(line[i]))
        }
        else {
            for (var spe of spelled) {
                if (line.substring(i, i+spe.length) == spe) {
                    real_digits.push(spelled.indexOf(spe)+1)
                    // i += spe.length - 1 //Línia completada per el copilot que em feia failejar:
                    // si la faig no es fa bé el oneight (hauria de ser 1 8) no només el de l'esquerra
                }
            }
        }
    }
    var digits = []
    for (const c of line) {
        if (c >= '0' && c <= '9') {
            digits.push(parseInt(c))
        }
    }
    suma += digits[0] * 10 + digits[digits.length - 1]
    suma2 += real_digits[0] * 10 + real_digits[real_digits.length - 1]
    //console.log(real_digits)
})
reader.on('close', () => {
    console.log(suma)
    console.log(suma2)
})