Drupal.VsiteVocab = Drupal.VsiteVocab || {};

Drupal.VsiteVocab.Rename = function(){
	var newTerm = prompt('new name');
    if (newTerm == null){
      return false;
    }
    var dest = $(this).attr('href');
    var slices = dest.split('/');
    
    var newDest = '';
    for (var i = 0; i < slices.length -1 ; i++ ){
    	newDest = newDest + slices[i] +  '/';
    }
    
	newDest =  newDest + newTerm;
	
	$(this).attr('href',newDest);
	return false;
}

Drupal.behaviors.vsitevocab = function(context) {
  var rename_link = $('ul.admin a.edit:not(.vsitevocab-processed)', context);
  var dest = rename_link.attr('href');	
  
  rename_link.click(Drupal.VsiteVocab.Rename);
  rename_link.click(Drupal.CTools.AJAX.clickAJAXLink);
}