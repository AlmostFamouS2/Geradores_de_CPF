let digits_cpf = String(Math.random()).split('').splice(9).join('')
let n1 = [10,9,8,7,6,5,4,3,2]
let n2 = [11,10,9,8,7,6,5,4,3,2]

let calc_nums = (cpf) => {  // Sim, eu criei isto.
    let sum = 0;

    for(let i = 0; i < digits_cpf.length; i++)
        sum += digits_cpf[i] * (cpf.length == 9 ? n1[i] : n2[i]);

    return (sum*10 % 11) == 10 ? 0 : sum*10 % 11;
}

digits_cpf += calc_nums(digits_cpf);
digits_cpf += calc_nums(digits_cpf);

console.log(digits_cpf)
