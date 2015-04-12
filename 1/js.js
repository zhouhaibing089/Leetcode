var twoSum = function(numbers, target) {
    var required = [];
    var hashed = {};

    numbers.forEach(function(value, index) {
        required.push(target - value);
        if (hashed[value + ""] === undefined) {
            hashed[value + ""] = [index];
        } else {
            hashed[value + ""].push(index);
        }
    });

    required = required.map(function(value) {
        return hashed[value + ""];
    });

    for (var i = 0; i < required.length; ++i) {
        var value = required[i];

        if (value === undefined) {
            continue;
        }
        if (value.length === 1) {
            if (value[0] === i) {
                continue ;
            }
            return [i + 1, value[0] + 1];
        }
        if (i === value[0]) {
            return [i + 1, value[1] + 1];
        }
    }
};
