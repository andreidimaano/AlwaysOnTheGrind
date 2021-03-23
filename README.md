# Eloquent Javascript Notes and Projects

## Chapters 1 - 6

### Closure
Addresses the questions what happens to a local binding/variable when the function call is no longer active.

For example:

```
function wrapValue(n) {
    let local = n;
    return () => local;
}

let wrap1 = wrapValue(1);
let wrap2 = wrap1(2);

console.log(wrap1());
// logs 1
console.log(wrap2());
// logs 2
```

As we know, all bindings are subject to scope. local is a local binding/variable in wrapValue(). Thus, we should not have access to local anymore correct? Incorrect - we are still able to reference a specific instance of a local binding in an enclosing scope. This feature is known as closure. A function that references bindings from local scopes is called a closure.

The Book describes functions as having both the code and the environment in which they are created. When called, the function body sees the environment in which it was created, not in which it is called.

### Rest Parameters
Bound to an array containing all further arguments. There can be other parameters before it when using it as a parameter in a function. 

Ex:
```
printWords("will", "never", "fully", "understand")

function printWords(arg1, arg2, ...words) {
    console.log(`${arg1} ${arg2} ${words}`)
}
```

You can also use the rest parameter to include an array with other arguments.

Ex:
```
let words = ["never", "fully"];
console.log(["will", ...words, "understand"]);
// logs ["will", "never", "fully", "understand"]
```
### Prototype

JS is not class-based liked Java or C++. JS is prototyped based. There is one construct that exists in JS - Objects. Each Object holds a property which holds a link to another object called its prototype. The prototype object has a prototype of its own - this chain continues until an object is reached with null as its prototype.

## Chapter 8 - 11

### Exceptions

Don't just blanket catch exceptions. When an exception makes it all the way to the bottom of the stack without being caught, it gets handled by the environment.

We want to catch a specific kind of exception. We can do this by checking in the catch block whtether the exception we got is the one we are interesting in and rethrowing it otherwise.

```
class InputError extends Error {}

function promptDirection(question) {
    let result = prompt(question);
    if (result.toLowerCase() == "left") return "L";
    if (result.toLowerCase() == "right") return "R";
    throw new InputError("Invalid direction: " + result);
}

try{
    //code here
} catch (e) {
    if (e instanceof InputError) {
        console.log()
    } else {
        throw e;
    }
}
```


