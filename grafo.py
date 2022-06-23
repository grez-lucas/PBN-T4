# This file was automatically generated by SWIG (http://www.swig.org).
# Version 4.0.2
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

from sys import version_info as _swig_python_version_info
if _swig_python_version_info < (2, 7, 0):
    raise RuntimeError("Python 2.7 or later required")

# Import the low-level C/C++ module
if __package__ or "." in __name__:
    from . import _grafo
else:
    import _grafo

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)


def _swig_setattr_nondynamic_instance_variable(set):
    def set_instance_attr(self, name, value):
        if name == "thisown":
            self.this.own(value)
        elif name == "this":
            set(self, name, value)
        elif hasattr(self, name) and isinstance(getattr(type(self), name), property):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add instance attributes to %s" % self)
    return set_instance_attr


def _swig_setattr_nondynamic_class_variable(set):
    def set_class_attr(cls, name, value):
        if hasattr(cls, name) and not isinstance(getattr(cls, name), property):
            set(cls, name, value)
        else:
            raise AttributeError("You cannot add class attributes to %s" % cls)
    return set_class_attr


def _swig_add_metaclass(metaclass):
    """Class decorator for adding a metaclass to a SWIG wrapped class - a slimmed down version of six.add_metaclass"""
    def wrapper(cls):
        return metaclass(cls.__name__, cls.__bases__, cls.__dict__.copy())
    return wrapper


class _SwigNonDynamicMeta(type):
    """Meta class to enforce nondynamic attributes (no new attributes) for a class"""
    __setattr__ = _swig_setattr_nondynamic_class_variable(type.__setattr__)


class Node(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    dest = property(_grafo.Node_dest_get, _grafo.Node_dest_set)
    next = property(_grafo.Node_next_get, _grafo.Node_next_set)

    def __init__(self):
        _grafo.Node_swiginit(self, _grafo.new_Node())
    __swig_destroy__ = _grafo.delete_Node

# Register Node in _grafo:
_grafo.Node_swigregister(Node)

class AdjacencyList(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    node = property(_grafo.AdjacencyList_node_get, _grafo.AdjacencyList_node_set)

    def __init__(self):
        _grafo.AdjacencyList_swiginit(self, _grafo.new_AdjacencyList())
    __swig_destroy__ = _grafo.delete_AdjacencyList

# Register AdjacencyList in _grafo:
_grafo.AdjacencyList_swigregister(AdjacencyList)

class Graph(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    nodeNum = property(_grafo.Graph_nodeNum_get, _grafo.Graph_nodeNum_set)
    AdjacencyLists = property(_grafo.Graph_AdjacencyLists_get, _grafo.Graph_AdjacencyLists_set)

    def __init__(self, *args):
        _grafo.Graph_swiginit(self, _grafo.new_Graph(*args))

    def newAdjListNode(self, arg2):
        return _grafo.Graph_newAdjListNode(self, arg2)

    def add_nodo(self):
        return _grafo.Graph_add_nodo(self)

    def add_arco(self, arg2, arg3):
        return _grafo.Graph_add_arco(self, arg2, arg3)

    def hay_arco(self, arg2, arg3):
        return _grafo.Graph_hay_arco(self, arg2, arg3)

    def hay_camino(self, arg2, arg3):
        return _grafo.Graph_hay_camino(self, arg2, arg3)

    def printGraph(self):
        return _grafo.Graph_printGraph(self)
    __swig_destroy__ = _grafo.delete_Graph

# Register Graph in _grafo:
_grafo.Graph_swigregister(Graph)



