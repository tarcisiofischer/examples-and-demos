from .somewhere import f

# f\(([^(^).]*)\)
# ($1).().f()
def g(x):
    my_var = (x).f()
    b = (my_var).f()
    return (
        my_var +
        b
    ).f()
