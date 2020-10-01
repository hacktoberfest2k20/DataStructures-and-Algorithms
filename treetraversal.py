# Binary Tree Class
class Node: 
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key
  
  
# Inorder tree traversal 
def printInorder(root):
    if root:
        printInorder(root.left)
        print(root.val)
        printInorder(root.right)
  
  
  
# Postorder tree traversal 
def printPostorder(root): 
  
    if root:
        printPostorder(root.left)
        printPostorder(root.right)
        print(root.val)
  
  
# Preorder tree traversal 
def printPreorder(root):
    if root:
        print(root.val)
        printPreorder(root.left)
        printPreorder(root.right)

