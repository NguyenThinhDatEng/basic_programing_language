- Introduce some built-in functions

1. Alert
2. Console
3. Confirm
4. Set timeout
5. Set interval

- Operator

1. Arithmetic
   1.1 Lũy thừa (\*\*)
   1.2 ++ (--)
   PreFix (++x)
   PostFix (x++)
2. Logical
   'A' && 'B' && 'C' == 'C'
   'A' || 'B' || 'C' == 'A'

- Data Type

1. Primitive Data
   1.1 Number
   1.2 String
   1.3 Boolean
   1.3.1 Truthy (Ex: 1, 'a', {})
   1.3.2 Falsy
   false
   0
   ''
   null
   undefined
   NaN
   1.4 Undefined
   1.5 Null
   1.6 Symbol
2. Complex Data
   Object
   Array

- Function

1. arguments
   Ex: show() {console.log(arguments)}; show(1, 2, 3); => [1, 2, 3]
2. Classification
   2.1. Declaration fn
   Ex: function a() {}
   Note: Can call this fn before declare fn
   2.2. Expression fn
   Ex: a = function() {}, setTimeout(function() {})
   Note: Can not call this fn before declare fn
   2.3. Arrow fn

- String

1. Backslash
2. Template string ES6 (`${variable}`)
3. Methods
   3.1. Find index of string (Fail => -1)
   indexOf(string) => Find first index
   indexOf(string, startIndex)
   lastIndexOf(string)
   search(string)
   3.2 Cut string
   slice(startIndex, endIndex);
   3.3 Replace string
   replace(oldString, newString); => Only replace first old string
   replace(/oldString/g, newString); => Replace all
   3.4 Convert to Array
   split(separatorString)
   3.5 Get Character by index
   string.charAt(index); => (Fail => '')
   string[index]; => (Fail => undefined)
   3.6 Check exist
   str.includes(anyStr, startIndex);

- Number

1. 1e2 (100)
2. Methods
   2.1. isFinite
   Number.isFinite(20/0) => False
   Number.isFinite(20/2) => True
   2.2. isInteger
   Number.isInteger(1) => True
   Number.isInteger(0.1) => False
   2.3. parseFloat
   Number.parseFloat('237.22.12') => 237.22
   Number.parseFloat('238,21') => 238
   Number.parseFloat(' 34 56 78 ') => 34
   Number.parseFloat('18 is my age') => 18
   2.4. parseInt
   Number.parseInt('237.22') => 237
   Number.parseInt(' 18 is my age') => 18
   2.5. toFixed (return string type)
   num.toFixed(fractionDigits)
   2.6. isNaN
   isNaN(num)

- Array

1. Methods
   1.1. toString()
   1.2. join(separatorString)
   1.3. Remove element => element
   1.3.1. pop() => last
   1.3.2. shift() => first
   1.4. Add element => length of arr
   1.4.1. push(element)
   1.4.2. unshift(element)
   1.5 splice => void
   Remove elements at: splice(index, noOfElement)
   Insert elements at: splice(index, 0, elements)
   Remove elements and Insert at: splice(index, noOfElement, elements)
   1.6. concat => new Arr
   orgArr.concat(value)
   1.7. Cut Arr => new arr
   arr.splice(firstIndex, lastIndex);
   1.8 Check exist
   arr.includes(value, startIndex);
2. Methods(value, index, orgArr)
   forEach
   every
   some
   map
   filter
   find
   reduce (init accumulator is optional)

- Object

1. Declaration
   const idKey = 'id';
   const entity = {
   [idKey]: 1,
   name: 'nvthinh'
   }
2. Object constructor
   function User(name, age) {
   this.name = name;
   this.age = age;
   this.getName = function() {return this.name}
   }
   const admin = new User('nvthinh', 23)
3. Object prototype (Nguyên mẫu)
   User.prototype.address = 'Bắc Ninh'
4. Date
5. Math
   Math.PI
   Math.round(num)
   Math.abs(num)
   Math.ceil(num) => Hàm trần
   Math.floor(num) => Hàm sàn
   Math.random() => (0 -> 1)

- Loop
  for
  for/in (key in object, index in array, character in string) => Does not filter through empty element
  for/of (array, string)

- Callback

1. Define
   1.1. is a function
   1.2. is passed through any arguments

- HTML DOM

1. Include
   Element
   Attribute
   Text
2. Get element methods
   id
   class
   tag (h1, h2, p, span, ...)
   CSS selector: querySelector (querySelectorAll)
   HTML Collection: document.forms(<form></form>), document.anchors(<a name="a"></a>), document.links(<a></a>)
3. Attribute
   element.setAttribute(attrName, value);
   element.getAttribute(attrName);
4. Text
   4.1. innerText ~ textContent
   4.1.1. InnerText (Những gì đang thấy trên giao diện)
   Chỉ lấy text của element hiện tại
   Bỏ qua các khoảng trống và elements khác khai báo bên trong element hiện tại
   Khi gán giá trị => Tự động chuyển các kí hiệu XSS đều được mã hóa thành string
   4.1.2. textContent (Lấy từ mã html)
   Lấy text của element hiện tại và text của các element khác (Kể cả display: none) khai báo bên trong element hiện tại (nếu có)
   Lấy cả các khoảng trống và text của các elements khác khai báo bên trong
   Khi gán giá trị => Tự động chuyển các thao tác đặc biệt về kí hiệu html (Ex: Xuống dòng => <br/>)

   4.2. innerHTML ~ outerHTML
   4.2.1. innerHTML
   element.innerHTML => Get all elements internal current element
   element.innerHTML = new element => Add a new element to current element
   4.2.2. outerHTML
   element.outerHTML => Get current element
   element.innerHTML = new element => Override current element by new element

5. Element
   5.1. style
   5.2. classList

6. Dom Events
   6.1. mouse
   onclick
   onmouseover

   6.2. input
   onchange
   oninput

   6.3 others
   onkeyup
   onkeydown
   onkeypress (except esc)

   6.4.
   PreventDefault
   StopPropagation

   6.5.
   addEventListener(event, func);
   removeEventListener(event, func);

7. Promise
   7.1. States
   7.1.1. Pending
   7.1.2. Fulfilled
   7.1.3. Rejected
   7.2. Functions
   Promise.Resolve()
   Promise.Reject()
   Promise.all([promise1, promise2, ...]).then(([result1, result2]) => {
   })

8. ECMAScript 6+
   8.1. Let & const <=> var (scoped, hosting)
   8.2. Template literals
   8.3. Arrow function
   8.4. Classes
   8.5. Default parameter values
   fn(name = "nvthinh")
   8.6. Enhanced object literals
   {name: name, fn: fn()} => {name, fn()}
   8.7. Destructuring, Rest
   {a, b, c, d: D, e = "E"} = obj
   [a, b, c] = arr
   [a, ...r] = arr
   8.8. Spread
   8.9. Tagged template literals
   fn`My name is ${name} and I am living in {country}`
   fn([first, ...strings], ...args)
   8.10. Modules
   export {default as moduleName} from './module.js
   8.11. Optional chaining (?.)

- Note

1. Can not use == operator to compare a variable with a special data type (Ex: undefined, NaN, ...)
