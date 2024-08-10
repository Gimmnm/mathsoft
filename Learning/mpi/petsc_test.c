#include <petscvec.h>  
  
int main(int argc,char **args)  
{  
    Vec            x;  // vectors  
    PetscErrorCode ierr;  
    PetscInt       i, n = 10;  
    PetscScalar    v;  
  
    ierr = PetscInitialize(&argc,&args,(char*)0,0);CHKERRQ(ierr);  
  
    // Create vectors  
    ierr = VecCreate(PETSC_COMM_WORLD,&x);CHKERRQ(ierr);  
    ierr = VecSetSizes(x,PETSC_DECIDE,n);CHKERRQ(ierr);  
    ierr = VecSetFromOptions(x);CHKERRQ(ierr);  
  
    // Set values  
    for (i=0; i<n; i++) {  
        v = i;  
        ierr = VecSetValues(x,1,&i,&v,INSERT_VALUES);CHKERRQ(ierr);  
    }  
  
    // Assemble vector  
    ierr = VecAssemblyBegin(x);CHKERRQ(ierr);  
    ierr = VecAssemblyEnd(x);CHKERRQ(ierr);  
  
    // Print vector  
    ierr = VecView(x,PETSC_VIEWER_STDOUT_WORLD);CHKERRQ(ierr);  
  
    // Free memory  
    ierr = VecDestroy(&x);CHKERRQ(ierr);  
  
    ierr = PetscFinalize();CHKERRQ(ierr);  
    return 0;  
}  