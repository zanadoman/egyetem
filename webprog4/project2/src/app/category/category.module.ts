import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { CategoriesListComponent } from './categories-list/categories-list.component';



@NgModule({
  declarations: [
    CategoriesListComponent
  ],
  exports: [
    CategoriesListComponent
  ],
  imports: [
    CommonModule
  ]
})
export class CategoryModule { }
