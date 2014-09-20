<?php

function ktopic_entity_metadata_kdata_getter_callback($data, array $options, $name, $type, $info) {
  return ktopic_get_kdata($data, $name);
}

class kdata_entity_views_handler_relationship extends views_handler_relationship {


  public function query() {
    parent::query();
    //dsm($this->view);
    //dsm($this->option_definition(), 'option definition');
    /*
    $table_data = views_fetch_data($this->definition['base']);

    $this->ensure_my_table();

    $def['table'] = $this->definition['base'];
    $def['field'] = 'id';
    $def['left_table'] = $this->table_alias;
    $def['left_field'] = '';

    dsm($table_data, $this->definition['base']);

    dsm($this->table_alias);
    dsm($this->real_field);


    dsm($this->query);
    */

    /*
    $table_data = views_fetch_data($this->definition['base']);
    dsm($table_data);

    $join = new views_join();
    $def['table'] = $this->definition['base'];
    $def['field'] = 'id';
    $def['left_table'] = 'entity_node';
    $def['left_field'] = 'field_ktopic_data';
    $join->definition = $def;
    $join->options = $this->options;
    $join->construct();
    $join->adjusted = TRUE;

    // use a short alias for this:
    $alias = $this->definition['base'] . '_' . $this->table;

    $this->alias = $this->query->add_relationship($alias, $join, $this->definition['base'], $this->relationship);

    */

  }


}
