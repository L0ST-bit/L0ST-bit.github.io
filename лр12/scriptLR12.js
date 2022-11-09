function validateForm(opts){
	let inputs = document.querySelectorAll(`#${opts.formId} input`)

	inputs.forEach(input=>{
		input.addEventListener('blur', validateInput)
		input.addEventListener('focus', removeErrorClassForInput)
	})

	let form =  document.querySelector(`#${opts.formId}`)
	form.addEventListener('submit',submitForm)

	function submitForm() {
		event.preventDefault()
		inputs.forEach(input=>{
			validateInput.call(input)
		})
		let isBad = false
		inputs.forEach(input=>{
			if (input.classList.contains(opts.inputErrorClass)) {
				isBad = true
			}
		})
		if (isBad) {
			form.classList.add(opts.formInvalidClass)
			form.classList.remove(opts.formValidClass)
		}else{
			form.classList.add(opts.formValidClass)
			form.classList.remove(opts.formInvalidClass)
		}
	}
	function validateInput(){
		if (this.dataset.required !== undefined && this.value.length === 0) {
			this.classList.toggle(opts.inputErrorClass, true)
		}
		let regex
		switch(this.dataset.validator){
			case "letters":
				regex = /^[а-яa-z]+$/i
				if (!regex.test(this.value)) {
					this.classList.toggle(opts.inputErrorClass, true)
				}
				break
			case "number":
				if (isNaN(this.value) || Number(this.dataset.validatorMin) > Number(this.value) || 
					Number(this.value) > Number(this.dataset.validatorMax)) {
					this.classList.toggle(opts.inputErrorClass, true)
				}
				break
			case "regexp":
				regex = new RegExp(this.dataset.validatorPattern)
				if (!regex.test(this.value) && this.value.length !== 0) {
					this.classList.toggle(opts.inputErrorClass, true)
				}
				break
		}
	}
	function removeErrorClassForInput(){
		this.classList.toggle(opts.inputErrorClass, false)
	}
}