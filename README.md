# Polynomials using Sorted Singly Linked Lists

A high-performance C++ class implementation designed to represent and manipulate single-variable polynomials with integer coefficients. This project was developed as part of **Exercise 9 (Polynomials)** for the *Programming Techniques* course at the **National Technical University of Athens (NTUA)**, School of Electrical and Computer Engineering.

---

## Technical Concept & Design

The `Polynomial` class represents a polynomial using a **strictly sorted, singly linked list**.

* **Ordered Monomials:** Nodes of the list (instances of class `Term`) are automatically maintained in strictly **descending order** of their exponents.
* **Algebraic Simplification:**
  * Duplicate exponents are automatically merged upon insertion (coefficients are summed).
  * Monomials with zero coefficients are suppressed to maintain simplified forms.
* **Operators & Evaluation:** * Implements `operator+` (polynomial addition) and `operator*` (polynomial multiplication).
  * Supports polynomial evaluation at any coordinate $x$ using `evaluate(double x)`.
  * Overloads the `operator<<` stream output stream to format and print the polynomial with natural mathematical notation (e.g., handling negative signs, suppressing redundant ones, and hiding $x^0$).

### Memory Layout Representation

For the polynomial $x^2 + 3x - 1$:

```text
 [ Head ] 
    │
    ▼
┌──────────────┐      ┌──────────────┐      ┌──────────────┐
│ Exponent:  2 │      │ Exponent:  1 │      │ Exponent:  0 │
│ Coeff:     1 │ ───► │ Coeff:     3 │ ───► │ Coeff:    -1 │ ───► [ nullptr ]
└──────────────┘      └──────────────┘      └──────────────┘
