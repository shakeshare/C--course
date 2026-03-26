int number(Bitree T)
{
    if(!T)
    {
        return 0;
    }
    else if(T->left&&!(T->right))
    {
        return number(T->left)+1;
    }
     else if(!(T->left)&&(T->right))
    {
        return number(T->right)+1;
    }
     else
    {
        return number(T->left)+number(T->right);
    }
}