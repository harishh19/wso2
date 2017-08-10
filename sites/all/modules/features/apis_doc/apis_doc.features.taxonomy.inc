<?php
/**
 * @file
 * apis_doc.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function apis_doc_taxonomy_default_vocabularies() {
  return array(
    'api_tags' => array(
      'name' => 'API Tags',
      'machine_name' => 'api_tags',
      'description' => 'Sealedair WSO2 API Tags',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
