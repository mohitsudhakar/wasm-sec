let productFunc;

function loadWasm(filename) {
	return fetch(filename)
		.then(response => response.arrayBuffer())
		.then(bits => WebAssembly.compile(bits))
		.then(module => { return new WebAssembly.Instance(module) });
}

loadWasm('product.wasm').then(instance => {
	productFunc = instance.exports.product;
});

function wasmProduct() {
	//converting the values to a number so they can be passed to wasm
	let x = parseInt(document.getElementById('num1').value);
	let y = parseInt(document.getElementById('num2').value);
	document.getElementById('answer').innerHTML = productFunc(x,y);
}

