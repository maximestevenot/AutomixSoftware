var fs = require('fs'),
    xml2js = require('xml2js');
	
var parser = new xml2js.Parser();
var path = "TestResults";

var tests = 0;
var tests_failed = 0;
var filesProcessed = 0;

fs.readdir( path, function( err, files ) {
	if( err ) {
		console.error( "Could not list the directory.\n", err );
		process.exit( 1 );
	} 
	files.forEach( function( file, index ) {
		fs.readFile( path + "\\" + file, function( err, data ) {
			parser.parseString(data, function( err, result ) {
				incr( parseInt(result.TestRun.ResultSummary.Counters.total), parseInt(result.TestRun.ResultSummary.Counters.failed), parseInt(result.TestRun.ResultSummary.Counters.executed), parseInt(result.TestRun.ResultSummary.Counters.error), function() {
					filesProcessed++;
					if( filesProcessed == files.length ) {
						console.log("(", ((tests - tests_failed)*100 / tests).toFixed(2), "%) of the tests suceeded.");
					}
				} );
			} );
		} );
		parser.reset();
	} );
});

function incr(t, t_f, t_s, t_e, callback) {
	tests += t_s;
	tests_failed += t_f + t_e;
	callback();
}